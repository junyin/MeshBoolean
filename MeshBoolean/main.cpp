#include <igl/readOFF.h>
//#define IGL_NO_CORK
//#undef IGL_STATIC_LIBRARY
#include <igl/copyleft/cgal/mesh_boolean.h>
#include <igl/viewer/Viewer.h>

#include <Eigen/Core>
#include <iostream>

Eigen::MatrixXd VA, VB, VC;
Eigen::MatrixXi FA, FB, FC;
igl::MeshBooleanType boolean_type(
	igl::MESH_BOOLEAN_TYPE_UNION);

const char * MESH_BOOLEAN_TYPE_NAMES[] =
{
	"Union",
	"Intersect",
	"Minus",
	"XOR",
	"Resolve",
};

int main(int argc, char *argv[])
{
	using namespace Eigen;
	using namespace std;

	if (argc != 5)
	{
		printf("Usage: inputA.obj inputB.obj inputC.obj boolean_type\n");
		printf("boolean_type: Union, Intersect, Minus, XOR, Resolve\n");
		exit(1);
	}


	igl::readOBJ( argv[1], VA, FA);
	igl::readOBJ( argv[2], VB, FB);

	if (strcmp(argv[4], MESH_BOOLEAN_TYPE_NAMES[0]) == 0)
		boolean_type = igl::MeshBooleanType(igl::MESH_BOOLEAN_TYPE_UNION);
	else if (strcmp(argv[4], MESH_BOOLEAN_TYPE_NAMES[1]) == 0)
		boolean_type = igl::MeshBooleanType(igl::MESH_BOOLEAN_TYPE_INTERSECT);
	else if (strcmp(argv[4], MESH_BOOLEAN_TYPE_NAMES[2]) == 0)
		boolean_type = igl::MeshBooleanType(igl::MESH_BOOLEAN_TYPE_MINUS);
	else if (strcmp(argv[4], MESH_BOOLEAN_TYPE_NAMES[3]) == 0)
		boolean_type = igl::MeshBooleanType(igl::MESH_BOOLEAN_TYPE_XOR);
	else if (strcmp(argv[4], MESH_BOOLEAN_TYPE_NAMES[4]) == 0)
		boolean_type = igl::MeshBooleanType(igl::MESH_BOOLEAN_TYPE_RESOLVE);
	else {
		printf("Wrong boolean_type!\n");
		printf("boolean_type: Union, Intersect, Minus, XOR, Resolve\n");
		exit(1);
	}

	igl::copyleft::cgal::mesh_boolean(VA, FA, VB, FB, boolean_type, VC, FC);

	igl::writeOBJ(argv[3], VC, FC);
	
}


