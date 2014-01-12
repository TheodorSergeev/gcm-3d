#ifndef _GCM_CONTACT_CONDITION_H
#define _GCM_CONTACT_CONDITION_H 1

#include "util/areas/Area.h"
#include "util/forms/PulseForm.h"
#include "calc/contact/ContactCalculator.h"

namespace gcm {
	class PulseForm;
	class CalcNode;

	class ContactCondition
	{
	public:
		ContactCondition();
		ContactCondition(Area* _area, PulseForm* _form, ContactCalculator* _calc);
		~ContactCondition();
	
		Area* area;
		PulseForm* form;
		ContactCalculator* calc;
		void do_calc(float time, CalcNode* cur_node, CalcNode* new_node, CalcNode* virt_node, ElasticMatrix3D* matrix, float* values[], bool inner[], ElasticMatrix3D* virt_matrix, float* virt_values[], bool virt_inner[], float outer_normal[]);
	};
}

#endif
