//
//  HTTPRequest
//

#include <iostream>
#include <fstream>
#include "HTTPRequest.h"

int main(int argc, const char *argv[]) {


    std::map<char, int> mymap;

    // first insert function version (single parameter):
    mymap.insert(std::pair<char, int>('a', 100));
    mymap.insert(std::pair<char, int>('z', 200));

    std::pair<std::map<char, int>::iterator, bool> ret;
    ret = mymap.insert(std::pair<char, int>('z', 500));
    if (ret.second == false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    std::map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, std::pair<char, int>('b', 300));  // max efficiency inserting
    mymap.insert(it, std::pair<char, int>('c', 400));  // no max efficiency inserting

    // third insert function version (range insertion):
    std::map<char, int> anothermap;
    anothermap.insert(mymap.begin(), mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it = anothermap.begin(); it != anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';


    std::string url = "http://www.99114.com/jst/";
    std::string method = "GET";
    std::string arguments = "{Host: www.99114.com}";
    std::vector<std::string> headers = {
            "Content-Type: application/x-www-form-urlencoded",
            "User-Agent: Baiduspider"
    };

    try {
        http::Request request(url);
        http::Response response = request.send(method, arguments, headers);
        std::string output;
        if (!output.empty()) {
            std::ofstream outfile(output, std::ofstream::binary);
            outfile.write(reinterpret_cast<const char *>(response.body.data()),
                          static_cast<std::streamsize>(response.body.size()));
        } else
            std::cout << response.body.data() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Request failed, error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}