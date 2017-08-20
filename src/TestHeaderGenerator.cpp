#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <rapidxml/rapidxml.hpp>

using namespace std;

std::map<std::string, std::string> values;
ofstream outputFile;

void create_map (const rapidxml::xml_document<> &doc, const std::string &mapName, bool name_to_value) {
    rapidxml::xml_node<> *child, *childchild;
    outputFile << "std::map<std::string, std::string> " << mapName << " = {";
    int i = 0;
    for (child = doc.first_node (); child; child = child->next_sibling ()) {
            for (childchild = child->first_node (); childchild; childchild = childchild->next_sibling ()) {
                cout << i << ") " << childchild->name ();
                cout << " = " << childchild->first_attribute ()->value () << endl;
                if (i) {
                    outputFile << ',';
                }
                outputFile << "\n{\"";
                if (name_to_value)
                    outputFile << childchild->name ();
                else
                    outputFile << childchild->first_attribute ()->value ();
                outputFile << "\",\"";
                if (name_to_value)
                    outputFile << childchild->first_attribute ()->value ();
                else
                    outputFile << childchild->name ();
                outputFile << "\"}";
                i++;
            }
        }
    outputFile << "};" << endl << endl;
}

void create_order (const rapidxml::xml_document<> &doc, const std::string &mapName, bool send_order) {
    rapidxml::xml_node<> *child, *childchild;
    outputFile << "std::vector<std::string> " << mapName << " { ";
    int i = 0;

    for (child = doc.first_node (); child; child = child->next_sibling ()) {
        childchild = child->first_node ();
        if (!send_order) {
            childchild = childchild->next_sibling ();
        }

        for (; childchild; childchild = childchild->next_sibling ()) {
            if (i) {
                outputFile << ",\n";
            }
            outputFile << "\"";
            outputFile << childchild->name ();
            outputFile << "\"";
            i++;
            if (childchild->next_sibling ())
                childchild = childchild->next_sibling ();
        }
    }
    outputFile << "};" << endl << endl;
}

void HeaderGenerator (const std::string &headerName, const std::vector<std::string> includeHeaders) {
    cout << headerName << endl;
    for (const auto i: includeHeaders)
      std::cout << i << endl;

    std::string outputHeader = headerName + ".hpp";
    outputFile.open(outputHeader);
    if (!outputFile.is_open()) {
        cout << "Output file not opened" << endl;
        return;
    }
    for (const auto i: includeHeaders)
        outputFile << "#include <" << i << ">" << endl;

    std::string inputXML = headerName + ".xml";
    ifstream myfile (inputXML);
    if (!myfile.is_open()) {
        cout << "Input file not opened" << endl;
        return;
    }

    outputFile << "#define COMMAND_ID_HEADER 3A" << endl << endl;

    vector<char> xmlFile ((istreambuf_iterator<char> (myfile)), istreambuf_iterator<char> ());
    rapidxml::xml_document<> doc;
    doc.parse<0> (xmlFile.data ());

    create_map(doc, std::string("str_to_byte"), true);
    create_map(doc, std::string("byte_to_str"), false);

    create_order(doc, std::string("snd_order"), true);
    create_order(doc, std::string("rcv_order"), false);
    outputFile.close ();
}

int main () {
    std::string headerName, includeName;
    std::vector<std::string> includeHeaders;
    cout << "Enter header name:" << endl;
    cin >> headerName;
    cout << "Enter includes(to stop CTRL+D):" << endl;
    while (cin >> includeName) {
        if (includeName.empty())
            break;
        includeHeaders.push_back(includeName);
    }
    HeaderGenerator (headerName, includeHeaders);
}

