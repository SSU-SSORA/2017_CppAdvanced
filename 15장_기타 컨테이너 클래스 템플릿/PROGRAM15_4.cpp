#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>

int main() {
	std::map<int, std::string> Employees;

	Employees[1923] = "½Å»çÀÓ´ç";

	Employees[5328] = "È«±æµ¿";

	Employees.insert(std::pair<int, const char * >(1924, "±èÈ«µµ"));

	Employees.insert(std::map<int, const char *>::value_type(7587, "±èÀ¯½Å"));

	Employees.insert(std::make_pair(5428, (char *)"ÀÌ¼ø½Å"));

	std::cout << "Employees[3374]= " << Employees[3374] << std::endl;
	std::cout << "Map size : " << Employees.size() << std::endl;
	Employees[3374];
	typedef std::unordered_multimap<std::string, int> MapType;
	MapType m;

	for (std::map<int, std::string>::iterator i = Employees.begin();
		i != Employees.end(); ++i) {

		std::cout << " [" << i->first << ": " << i->second << "] ";

		if (!i->second.empty())
			m.insert(std::make_pair((*i).second, i->first));
	}
	std::cout << std::endl;

	m.emplace("È«±æµ¿", 9324);
	m.emplace(std::make_pair("È«±æµ¿", 0001));

	std::cout << " mÀÇ ¿ä¼Ò : " << std::endl;
	for (MapType::iterator it = m.begin();
		it != m.end(); ++it) {
		std::cout << " [" << it->first << ", " << it->second << "] ";
	}

	std::cout << std::endl;
	std::string s = "È«±æµ¿";
	std::cout << "È«±æµ¿ : " << m.count(s);
	std::pair<MapType::iterator, MapType::iterator> ppp = m.equal_range(s);

	std::cout << "Range of \"" << s << "\" elements : " << std::endl;
	for (MapType::iterator it2 = ppp.first; it2 != ppp.second; ++it2) {
		std::cout << " [" << it2->first << ", " << it2->second << "] ";
	}
	std::cout << std::endl;

	m.clear();
	return 0;



}