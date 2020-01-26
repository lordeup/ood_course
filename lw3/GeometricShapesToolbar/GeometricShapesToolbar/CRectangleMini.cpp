#include "CRectangleMini.h"

CRectangleMini::CRectangleMini(CToolbar& toolbar)
	: m_toolbar(toolbar)
{
}

void CRectangleMini::Execute()
{
	m_toolbar.CreateToolbar();
}
