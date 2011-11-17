#ifndef _GCM_SNAPSHOT_WRITER_H
#define _GCM_SNAPSHOT_WRITER_H  1

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::ofstream;
using std::stringstream;

#include "../datatypes/ElasticNode.h"
#include "../meshtypes/TetrMesh_1stOrder.h"

#include <vtkUnstructuredGrid.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkTetra.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkstd/string>

class SnapshotWriter
{
public:
	SnapshotWriter();
	~SnapshotWriter();
	string* get_snapshot_writer_type();
	int dump_vtk(TetrMesh_1stOrder* tetr_mesh, int zone_num, int snap_num);
	void attach(Logger* new_logger);
	int dump_tetr_mesh(TetrMesh_1stOrder* tetr_mesh, int zone_num, int snap_num);

protected:
	string snapshot_writer_type;
	Logger* logger;
};

#include "SnapshotWriter.inl"

#endif
