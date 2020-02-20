#ifdef SIM_STATIC_LIBRARY
# include<../include/linear_tri2d_tester_dq.h>
#endif

template<typename HessianType, typename DefoType, typename DerivedV, typename Scalar, typename DerivedParams>
void sim::linear_tri2d_tester_dq(Eigen::DenseBase<HessianType> &out, const Eigen::MatrixBase<DerivedV> &q, const Eigen::Ref<const Eigen::RowVectorXi> element,  
                                    const Eigen::MatrixBase<DefoType> &dXinv, const Scalar &volume, Eigen::MatrixBase<DerivedParams> &params) {

    Eigen::Vector6x<Scalar> qe; qe << q.segment(2*element(0),3), q.segment(2*element(1),3), q.segment(2*element(2),3); //qe
    Eigen::Matrix3x<Eigen::Matrix<ypename DefoType::Scalar> F = Eigen::Matrix3x<typename DerivedV::Scalar>::Zero();  Eigen::Vector9x<typename DerivedV::Scalar> one = Eigen::Vector9x<typename DerivedV::Scalar>::Zero(); one(8) = 1.0; P<<1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0; F.block(0,0,3,2) = dXinv; Eigen::Matrix<typename DefoType::Scalar, 9,6> B = sim::flatten_multiply_right<Eigen::Matrix<typename DefoType::Scalar, 3,3> >(F)*P; //compute B

    Eigen::Vector9x<Scalar> dF; //type of dF

    d2psi_tester_dF(dF, unflatten<3,3>((B*qe+one).eval()), volume, params);

    out = B.transpose()*dF;

}
