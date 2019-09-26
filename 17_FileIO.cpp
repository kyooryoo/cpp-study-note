// pay attention to:
// * how to use PI constant from library
// * the function fopen for opening a file
// * the function fwrite and fread for file IO
// * the functoin fclose and delete after use
// * the use of pointer such as *data_in and &header

//const double PI = 3.14159;
#include <iostream>
#include <cmath>
using namespace std;

typedef struct FileHeader {
	int Points;
	int Year;
	int Month;
	int Day;
} FileHeader;

int main() {
	// create some data
	FileHeader header;
	header.Points = 11;
	header.Year = 2019;
	header.Month = 9;
	header.Day = 25;
	
	double *data_in = new double[header.Points]();
	for(int i = 0; i < header.Points; i++) {
		data_in[i] = sin(i/((double) header.Points - 1)*2*M_PI);
	}

	// print the data
	cout << "created data on " << header.Month << "/" 
		<< header.Day << "/" << header.Year << ":" << endl;
	for(int i = 0; i < header.Points; i++) {
		cout << data_in[i] << endl;
	}
		
	// write the file
	FILE* file_in = fopen("17_StructFile.dat", "wb");
	fwrite(&header, sizeof(FileHeader), 1, file_in);
	fwrite(data_in, sizeof(double), header.Points, file_in);
	fclose(file_in);
	
	delete[] data_in;	

	// read the file
	FILE* file_out = fopen("17_StructFile.dat", "rb");
	fread(&header, sizeof(FileHeader), 1, file_out);
	double *data_out = new double[header.Points];
	fread(data_out, sizeof(double), header.Points, file_out);
	fclose(file_out);

	// print out file contents
	cout << "file contents:" << endl;
	for(int i = 0; i < header.Points; i++) {
		cout << data_out[i] << endl;
	}
	
	delete[] data_out;
	return 0;
}
