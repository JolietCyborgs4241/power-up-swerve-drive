#pragma once

#include <math.h>

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include "PIDSource.h"
#include "ctre/Phoenix.h"
#include "ctre/phoenix/Sensors/PigeonIMU.h"

class Pigeon : public Subsystem {
<<<<<<< HEAD
private:
	PigeonIMU* pigeon;

	double const COLLISION_THRESHOLD_DELTA_G = 0.5;
	double const TILTED_THRESHOLD_DEGREES = 10;

	double previous_accel_X = 0;
	double previous_accel_Y = 0;

	double yaw = 0;
	double pitch = 0;
	double roll = 0;

public:
	Pigeon();
	void CalibratePigeon();
	void InitDefaultCommand();
	void Update();
	bool AmTilted();
	double GetYaw();
	bool WasCollision();
	void ResetYaw();
};

#endif  // Pigeon_H
/*
class Book {
private:
	int pages;

public:
	std::string name;
	std::string authors[];
	std::string chapters[];

	Book(std::string name, std::string author, std::string chapters[]);
	Book(std::string name, std::string authors[], std::string chapters[]);


	void GetInfo();
	void GetChapter(int chapterNumber);
	void SetPages(int numOfPages);
};

// C++ FILE v

Book::Book(std::string name, std::string author, std::string chapters[]) {
	this->name = name;
	this->authors = {author};
	this->chapters = chapters;

	pages = 20;
}

Book::Book(std::string name, std::string authors[], std::string chapters[]) {
	this->name = name;
	this->authors = authors;
	this->chapters = chapters;
}

void Book::GetInfo() {
}

void Book::GetChapter(int chapterNum) {

}

void Book::SetPages(int num) {
	if (num < 0) {
		pages = 0;
	} else {
		pages = num;
	}
}

int Book::GetPages() {
	return pages;
}

Book book1 = Book("My Cats and I", "Connelly", {"Chapter 1: My cats...", "", ""});
book1->SetPages(5);
print << book1->GetPages();


*/
=======
  private:
    PigeonIMU* pigeon;

    double const COLLISION_THRESHOLD_DELTA_G = 0.3;
    double const TILTED_THRESHOLD_DEGREES = 10;

    double previous_accel_X = 0;
    double previous_accel_Y = 0;

    double yaw = 0;
    double pitch = 0;
    double roll = 0;

    double originalRoll = 0;
    double originalPitch = 0;

  public:
    Pigeon();
    void CalibratePigeon();
    void InitDefaultCommand();
    void Update();
    bool AmTilted();
    double GetYaw();
    bool WasCollision();
    void SaveTilt();
    void ResetYaw(double angle = 0);
};
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
