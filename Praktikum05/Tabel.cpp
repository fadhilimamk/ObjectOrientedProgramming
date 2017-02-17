#include "Tabel.h"

Tabel::Tabel(){
	int i = 0;
	data_ = new int[defaultSize];
	size = defaultSize;
	for(i = 0; i < defaultSize ; i++){
		data_[i] = Nil;
	}
}

Tabel::Tabel(int size){
	int i = 0;
	data_ = new int[size];
	this->size = size;
	for(i = 0; i < size ; i++){
		data_[i] = Nil;
	}
}

Tabel::Tabel(const Tabel &t){
	size = t.size;
	data_ = new int[size];
	for(int i = 0; i < size ; i++){
		data_[i] = t.data_[i];
	}
}

Tabel::~Tabel(){
	delete data_;
}

Tabel& Tabel::operator=(const Tabel &t){
	if( this != &t){
		delete data_;
		this->size = t.size;
		data_ = new int[this->size];
		for(int i = 0; i < size ; i++){
			data_[i] = t.data_[i];
		}
	}
	return (*this);
}

int Tabel::GetSize(){
	return size;
}

int* Tabel::GetData(){
	return data_;
}

bool Tabel::IsEmpty(){
	bool found = false; int i = 0;
	while(i<size && !found){
		if(data_[i]!=Nil)
			found = true;
		else
			i++;
	}
	return !found;
}


bool Tabel::IsFull(){
	bool found = false; int i = 0;
	while(i<size && !found){
		if(data_[i]==Nil)
			found = true;
		else
			i++;
	}
	return !found;
}

void Tabel::Add(int x){
	bool found = false; int last = 0;
	while(last<size && !found){
		if(data_[last]==Nil)
			found = true;
		else
			last++;
	}
	data_[last] = x;
}

int Tabel::Del(int i){
	int temp = data_[i];
	data_[i] = Nil;
	return temp;
}

void Tabel::DelX(int x){
	bool found = false; int last = 0;
	while(last<size && !found){
		if(data_[last]==x)
			found = true;
		else
			last++;
	}
	data_[last] = Nil;
}

int Tabel::NbElmt(){
	int count = 0, i;
	for(i = 0; i < size; i++){
		if(data_[i] != Nil)
			count++;
	}
	return count;
}

int Tabel::Sum(){
	int count = 0, i;
	for(i = 0; i < size; i++){
		if(data_[i] != Nil)
			count+=data_[i];
	}
	return count;
}

bool Tabel::Or(){
	bool found = false; int i = 0;
	while(i<size && !found){
		if(data_[i]==1)
			found = true;
		else
			i++;
	}
	return found;
}

Tabel Tabel::Accumulate(){
	Tabel temp(1);
	temp.Add((*this).Sum());
	return temp;
}

bool Tabel::IsEq(Tabel t){
	bool equal = true; int i =0;
	if(t.size == size){
		while(i<size && equal){
			if(t.data_[i] != data_[i])
				equal = false;
			else
				i++;
		}
		return equal;
	}else{
		return false;
	}
}

bool Tabel::IsBit(int i){
	return (data_[i] == 0 || data_[i] == 1);
}
