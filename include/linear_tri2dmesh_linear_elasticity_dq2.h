#ifndef SIM_LINEAR_TRI2DMESH_LINEAR_ELASTICITY_DQ2_H
#define SIM_LINEAR_TRI2DMESH_LINEAR_ELASTICITY_DQ2_H

#include <Eigen/Dense>
#include <EigenTypes.h>

#include <assemble.h>
#include <linear_tri2d_linear_elasticity_dq2.h>


namespace sim {

template<typename DerivedRet, int Options, typename StorageIndex, typename DerivedV, typename DerivedQ, typename DefoType, typename DerivedVol, 
         typename DerivedParam, 
         class ElementMatrixCallback = decltype(default_callback)>
void linear_tri2dmesh_linear_elasticity_dq2(Eigen::SparseMatrix<DerivedRet, Options, StorageIndex> &H, Eigen::DenseBase<DerivedV> &V,  Eigen::Ref<const Eigen::MatrixXi> E,
                                        const Eigen::MatrixBase<DerivedQ> &q, 
                                        const Eigen::MatrixBase<DefoType> &dXinv, const Eigen::MatrixBase<DerivedVol>  &volume, 
                                        const Eigen::MatrixBase<DerivedParam> &params,
                                        const ElementMatrixCallback func = default_callback);



}

#ifndef SIM_STATIC_LIBRARY
#   include <../src/linear_tri2dmesh_linear_elasticity_dq2.cpp>
#endif

#endif