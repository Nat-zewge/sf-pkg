/**
 * @file 
 * @author Denise Ratasich
 * @date 24.07.2013
 *
 * @brief Header file of a (simple) moving median filter.
 */

#ifndef __ESTIMATION_MOVING_MEDIAN_H__
#define __ESTIMATION_MOVING_MEDIAN_H__

#include "estimation/IEstimationMethod.h"
#include "estimation/InputValue.h"
#include "estimation/OutputValue.h"
#include <deque>

namespace estimation 
{

  class MovingMedian : public IEstimationMethod
  { 
    /** @brief Input data. */
    std::deque<Input> in;
    /** @brief Result of an estimation, i.e. representation of an
     * estimate. */
    Output out;

    /** @brief The number of data values to use for estimation. */
    unsigned int windowSize;

  public: 
    /**
     * @brief Constructor of this class.
     */
    MovingMedian ();

    /**
     * @brief Destructor of this class.
     */
    ~MovingMedian ();

    /** 
     * @brief Sets the window size.
     *
     * @param windowSize Number of input values used for estimation,
     * i.e. length of moving window over the data stream (input
     * values).
     */
    void setWindowSize (unsigned int windowSize);

    /**
     * @brief Returns an estimate calculated with the given new data
     * value.
     */
    Output estimate (Input next);

    /**
     * @brief Returns the last estimated value.
     */
    Output getLastEstimate (void);
  };

}

#endif