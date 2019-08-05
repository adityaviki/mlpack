/**
 * @file lregularizer.hpp
 * @author Saksham Bansal
 *
 * Generalized L-regularizer, allowing both l1 and l2 regularization methods.
 * This also gives several convenience typedefs for commonly used L-regularizers.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_METHODS_ANN_LREGULARIZER_HPP
#define MLPACK_METHODS_ANN_LREGULARIZER_HPP

#include <mlpack/prereqs.hpp>

namespace mlpack {
namespace ann {

/**
 * The L_p regularizer for arbitrary integer p.
 *
 * @tparam Power Power of regularizer; i.e. Power = 1 gives the L1-regularization.
 */
template<int TPower>
class LRegularizer
{
 public:
  /**
   * Create the regularizer object.
   *
   * @param factor The factor for regularization.
   */
  LRegularizer(double factor = 1.0);

  /**
   * Calculate the gradient for regularization.
   *
   * @tparam MatType Type of weight matrix.
   * @param weight The weight matrix to be regularized.
   * @param gradient The calculated gradient.
   */
  template<typename MatType>
  void Evaluate(const MatType& weight, MatType& gradient);

  //! Serialize the regularizer (nothing to do).
  template<typename Archive>
  void serialize(Archive& ar, const unsigned int /* version */);

  //! The power of the regularizer.
  static const int Power = TPower;

  //! The constant for the regularization
  const int factor;
};

// Convenience typedefs.
/**
 * The L1 Regularizer.
 */
typedef LRegularizer<1> L1Regularizer;

/**
 * The L2 Regularizer.
 */
typedef LRegularizer<2> L2Regularizer;

} // namespace ann
} // namespace mlpack

// Include implementation.
#include "lregularizer_impl.hpp"

#endif
