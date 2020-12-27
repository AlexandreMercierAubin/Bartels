#ifdef SIM_STATIC_LIBRARY
# include<../include/search_direction_newton_sparse.h>
#endif

template<typename DerivedG, typename DerivedH, class SparseLinearSolver>
bool sim::search_direction_newton_sparse(Eigen::MatrixBase<DerivedG> &d, 
                                         const Eigen::MatrixBase<DerivedG> &g, 
                                         const Eigen::MatrixBase<DerivedH> &H, 
                                         SparseLinearSolver &solver) {

    
    solver.compute(H);

    if(solver.info()!=Eigen::Success) {
        return false;
    }
    
    d = solver.solve(-g);
    
    if(solver.info()!=Eigen::Success) {
        return false;
    }

    return true; 

}