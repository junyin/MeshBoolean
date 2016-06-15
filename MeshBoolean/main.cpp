#include <igl/readOBJ.h>
#include <igl/viewer/Viewer.h>

Eigen::MatrixXd V;
Eigen::MatrixXi F;

int main(int argc, char *argv[])
{
	// Load a mesh in OFF format
	igl::readOBJ("../data/bunny.obj", V, F);

	// Plot the mesh
	igl::viewer::Viewer viewer;
	viewer.data.set_mesh(V, F);
	viewer.launch();
}