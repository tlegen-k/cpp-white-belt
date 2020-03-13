#include <iostream>
#include <string>
using namespace std;

struct Specialization {
	string value;
	explicit Specialization (string new_value) {
		value = new_value;
	}
};

struct Course {
	string value;
	explicit Course (string new_value) {
		value = new_value;
	}
};

struct Week {
	string value;
	explicit Week (string new_value) {
		value = new_value;
	}
};
struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle (Specialization new_specialization, Course new_course, Week new_week) {
	  specialization = new_specialization.value;
	  course = new_course.value;
	  week = new_week.value;
  }
};

void PrintLectureTitle (const LectureTitle& lectureTitle)
{
	cout << lectureTitle.specialization << " - " << lectureTitle.course << " - " <<
			lectureTitle.week << endl;
}
int main(){
	LectureTitle lectureTitle = {Specialization{"C++"}, Course{"white belt"}, Week{"3rd"}};
	PrintLectureTitle(lectureTitle);
	return 0;
}
