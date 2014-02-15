#ifndef GCM_BASIC_CUBIC_MESH_H_
#define GCM_BASIC_CUBIC_MESH_H_

#include "mesh/Mesh.h"
#include "Math.h"
#include "Logging.h"
#include "Exception.h"

#include "interpolator/LineFirstOrderInterpolator.h"

using namespace gcm;

namespace gcm
{
	class CalcNode;
	
	class BasicCubicMesh: public Mesh {
		
	// Hopefully we will never need these 'friends' back
/*	friend class VTKSnapshotWriter;
	friend class DataBus;
	friend class CollisionDetector;
	friend class BruteforceCollisionDetector;
*/		
	
	private:
		LineFirstOrderInterpolator* interpolator;
	
	protected:
		void logMeshStats();
		void calcMinH();
		void preProcessGeometry();
		
		float meshH;
		
		USE_LOGGER;
		
	public:
		BasicCubicMesh();
		~BasicCubicMesh();
		
		float getRecommendedTimeStep();
		float getMinH();
		void doNextPartStep(float tau, int stage);
		void checkTopology(float tau);
		
		void findBorderNodeNormal(int border_node_index, float* x, float* y, float* z, bool debug);
		int findTargetPoint(CalcNode* node, float dx, float dy, float dz, bool debug, float* coords, bool* innerPoint);


		void interpolateNode(CalcNode& origin, float dx, float dy, float dz, bool debug, 
								CalcNode& targetNode, bool& isInnerPoint);
	};
}
#endif
