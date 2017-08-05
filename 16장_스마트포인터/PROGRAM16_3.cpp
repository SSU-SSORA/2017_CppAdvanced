#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class Song {
	std::string title_;
	std::string artist_;
public:
	Song(std::string title, std::string artist = "Unknown")
		:title_(title), artist_(artist) {
		std::cout << "Create Song(" << title_.data() << ", "
			<< artist_.data() << ")" << std::endl;
	}
	~Song() {
		std::cout << "Delete Song(" << title_.data() << ", "
			<< artist_.data() << ')'
			<< std::endl;
	}
	const char * GetTitle() const {
		return title_.data();
	}
	const char * GetArtist() const {
		return artist_.data();
	}
};

int main() {
	std::shared_ptr<Song> sp0(new Song("Ode to Joy", "베토벤"));
	std::cout << sp0->GetTitle() << ", use count : " << sp0.use_count() << '\n';

	auto sp1 = std::make_shared<Song>("Yesterday", "비틀즈");

	std::shared_ptr<Song> sp2(sp1);
	std::cout << sp1->GetTitle() << ", use count : " << sp1.use_count() << '\n';

	sp2.reset(new Song("Blackbird", "비틀즈"));

	auto sp3 = std::make_shared<Song>("Greensleeves", "영국 전통 민요");

	std::shared_ptr<Song> sp4;

	sp4 = std::make_shared<Song>("i'm still standing", "엘튼 존");
	std::vector<std::shared_ptr<Song>> playList;

	playList.push_back(std::move(sp0));
	playList.push_back(std::move(sp1));
	playList.push_back(std::move(sp2));

	playList.push_back(sp3);
	playList.push_back(sp4);

	for (auto& sp : playList) {
		std::cout << "Playing" << sp->GetTitle()
			<< " by " << sp->GetArtist() << ", use count : "
			<< sp.use_count() << std::endl;
	}
}