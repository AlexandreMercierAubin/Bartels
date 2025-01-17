
#ifndef SIM_LINEAR_TETMESH_CONST_EXT_FORCE_H
#define SIM_LINEAR_TETMESH_CONST_EXT_FORCE_H

#include <Eigen/Dense>
#include <EigenTypes.h>

#include <linear_tri3dmesh_dphi_dX.h>
#include <assemble.h>

namespace sim {
    
    template<typename DerivedRet, int Options, typename StorageIndex, typename DerivedV>
    void linear_tri3dmesh_B(Eigen::SparseMatrix<DerivedRet, Options, StorageIndex> &B, const Eigen::MatrixBase<DerivedV> &V,  Eigen::Ref<const Eigen::MatrixXi> E);
}

#ifndef SIM_STATIC_LIBRARY
#   include <../src/linear_tri3dmesh_B.cpp>
#endif

#endif