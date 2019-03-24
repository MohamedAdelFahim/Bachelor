#include "pch.h"

#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <ctime>
#include <list>
#include <cassert>
#include <chrono>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/Delaunay_triangulation_cell_base_3.h>
#include <CGAL/Triangulation_vertex_base_with_info_3.h>
#include <CGAL/IO/Color.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/point_generators_3.h>
#include <CGAL/draw_triangulation_3.h>
#include <CGAL/Triangulation_3.h>
#include <CGAL/convex_hull_3.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel         K;
typedef CGAL::Triangulation_vertex_base_with_info_3<CGAL::Color, K> Vb;
typedef CGAL::Delaunay_triangulation_cell_base_3<K>                 Cb;
typedef CGAL::Triangulation_data_structure_3<Vb, Cb>                Tds;
typedef CGAL::Delaunay_triangulation_3<K, Tds>                      Delaunay;
typedef Delaunay::Point                                             Point;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K>                   DT3;
typedef CGAL::Creator_uniform_3<double, K::Point_3>          Creator;
typedef CGAL::Triangulation_3<K>      Triangulation;




//Delaunay brain;
using namespace std;


int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	Triangulation tringulatedShape;
	cout << "starting" << endl;
	std::ifstream iFileT("TriangulatedOutput", std::ios::in);
	iFileT >> tringulatedShape;
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;

	cout << "Elapsed time: " << elapsed.count() / 60 << " m\n";

	CGAL::draw(tringulatedShape);
	
	auto finish2 = chrono::high_resolution_clock::now();
	chrono::duration<double> endTime = finish2 - start;

	cout << "Elapsed time: " << endTime.count() / 60 << " m\n";

	return EXIT_SUCCESS;
}
