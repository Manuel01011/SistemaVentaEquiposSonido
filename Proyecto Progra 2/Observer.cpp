#include "Observer.h"

Observer::Observer(Subject* mod) : model(mod){}

Observer::~Observer(){}

Subject* Observer::getSubject(){return model;}

ostream& operator<<(ostream& out, Observer& o){
	out << " ";
	return out;
}