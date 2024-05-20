#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
// #include <omp.h>
#include <chrono>
#include "sorting.h"

using namespace std;

// benchmark functions
void benchmark_quicksort();
void benchmark_mergesort();
void benchmark_heapsort();
void benchmark_shellsort_2n();

int main(int argc, char **argv)
{

	Catch::Session().run();

	std::cout << "\nPress Enter to run measurement" << std::endl;
	std::cin.get();

	benchmark_quicksort();
	benchmark_mergesort();
	benchmark_heapsort();
	benchmark_shellsort_2n();

	return 0;
}

// executes benchmark for quicksort
void benchmark_quicksort()
{

	// file stream
	ofstream quicksort_measurement;
	quicksort_measurement.open("quicksort.txt", ios::out | ios::app);

	// benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	// actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step)
	{

		//"progress bar"
		std::cout << "Running Quicksort with n: " << n << std::endl;

		auto result = std::chrono::steady_clock::duration::zero();
		for (int i = 0; i < 10; i++)
		{
			// generate n random integers
			sorting::randomizeVector(V, n);

			// start measurement
			// dtime = omp_get_wtime();
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			// execzute sorting algorithm
			sorting::QuickSort(V, 0, V.size() - 1);

			// stop time
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			auto dtime = end - begin;
			// dtime = omp_get_wtime() - dtime;
			result += dtime;
		}
		result /= 10;
		// write to file
		quicksort_measurement << n << "\t" << setprecision(10) << scientific << result.count() << endl;
	}

	// close file handle
	quicksort_measurement.close();
}

void benchmark_mergesort()
{
	// file stream
	ofstream mergesort_measurement;
	mergesort_measurement.open("mergesort.txt", ios::out | ios::app);

	// benchmark parameters / variables
	// double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;
	vector<int> temp_array;

	// actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step)
	{

		//"progress bar"
		std::cout << "Running Mergesort with n: " << n << std::endl;

		auto result = std::chrono::steady_clock::duration::zero();
		for (int i = 0; i < 10; i++)
		{
			// generate n random integers
			sorting::randomizeVector(V, n);

			// start measurement
			// dtime = omp_get_wtime();
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			// execzute sorting algorithm
			temp_array.resize(V.size());
			sorting::MergeSort(V, temp_array, 0, V.size() - 1);

			// stop time
			auto dtime = std::chrono::steady_clock::now() - begin;
			// dtime = omp_get_wtime() - dtime;
			result += dtime;
		}
		result /= 10;

		// write to file
		mergesort_measurement << n << "\t" << setprecision(10) << scientific << result.count() << endl;
	}

	// close file handle
	mergesort_measurement.close();
}

void benchmark_heapsort()
{
	// file stream
	ofstream heapsort_measurement;
	heapsort_measurement.open("heapsort.txt", ios::out | ios::app);

	// benchmark parameters / variables
	// double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	// actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step)
	{

		//"progress bar"
		std::cout << "Running Heapsort with n: " << n << std::endl;

		auto result = std::chrono::steady_clock::duration::zero();
		for (int i = 0; i < 10; i++)
		{
			// generate n random integers
			sorting::randomizeVector(V, n);

			// start measurement
			// dtime = omp_get_wtime();
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			// execute sorting algorithm
			sorting::HeapSort(V, V.size());

			// stop time
			// dtime = omp_get_wtime() - dtime;
			auto dtime = std::chrono::steady_clock::now() - begin;
			result += dtime;
		}
		result /= 10;

		// write to file
		heapsort_measurement << n << "\t" << setprecision(10) << scientific << result.count() << endl;
	}

	// close file handle
	heapsort_measurement.close();
}

void benchmark_shellsort_2n()
{
	// file stream
	ofstream shellsort_measurement;
	shellsort_measurement.open("shellsort_2n.txt", ios::out | ios::app);

	// benchmark parameters / variables
	// double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	// actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step)
	{
		//"progress bar"
		std::cout << "Running Shellsort_2n with n: " << n << std::endl;

		auto result = std::chrono::steady_clock::duration::zero();
		for (int i = 0; i < 10; i++)
		{
			// generate n random integers
			sorting::randomizeVector(V, n);

			// start measurement
			// dtime = omp_get_wtime();
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			// execute sorting algorithm
			sorting::ShellSort_2n(V, V.size());

			// stop time
			// dtime = omp_get_wtime() - dtime;
			auto dtime = std::chrono::steady_clock::now() - begin;
			result += dtime;
		}
		result /= 10;

		// write to file
		shellsort_measurement << n << "\t" << setprecision(10) << scientific << result.count() << endl;
	}

	// close file handle
	shellsort_measurement.close();
}
