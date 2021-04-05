/*
	Created by Jiahe Chen 
*/

#ifndef COSAN_METRIC_H
#define COSAN_METRIC_H

// TODO: change after integrate with module

// import from other lib
#include<string>
#include<exception>
#include<Eigen/Dense>

// import from Cosan
#include<ArgCheck.h>
#include<Exception.h>
#include<cosan/data/CosanData.h>

namespace Cosan
{
	/*
		Base class for metric function
	*/
	class CosanMetric
	{
		CosanMatrix& yTrue;
		CosanMatrix& yPredict;

		public:
			/*
				Default constructor 
			*/
			CosanMetric(CosanMatrix& y1, CosanMatrix& y2)
			{
				// check if the input matrices have the same size
				if (!SameSize(yTrue, yPredict))
				{
					throw DiffSize;
				}

				// check the shape of the input
				if (!LabelShape(yTrue))
				{
					throw InvalidLabelShape;
				}

				// TODO: type check if the input type gets expanded

				yTrue{y1}; 
				yPredict{y2};
			};


			// Destructor
			CosanMetric()=delete;


		// returns the error rate
		virtual double GetError(){}=0;
	};

	/*
	count the number of errors in a prediction
	Parameters:
		yTrue: a refrence to a CosanMatrix object; the real labels
			   with a shape of (#_of_samples, 1)
		yPredict: a refrence to a CosanMatrix object; the predicted labels
				  with a shape of (#_of_samples, 1)
		threshold: double; threshold for error
	Output of GetError:
		result: double; number of mismatch between predicted
				and real labels
	*/
	class NumOfError: public CosanMetric
	{
		double Mthreshold;

		public:
			NumOfError(CosanMatrix& y1, CosanMatrix& y2, double threshold): CosanMetric(y1, y2)
			{
				Mthreshold{threshold};
			}

		double GetError()
		{
			return ((yTrue - yPredict) > Mthreshold).count();
		}
	};

	
	/*
	Mean absolute error
	Parameters:
		yTrue: see in error_num cooments
		yPredict: see in error_num cooments
	Output of GetError:
		result: double; refer to 
				https://scikit-learn.org/stable/modules/model_evaluation.html#mean-absolute-error
	*/
	class MabsError: public CosanMetric
	{
		// TODO: might get an error. class ihenritance grammar errors

		double GetError()
		{
			return (yTrue - yPredict).abs().sum()/yTrue.rows();
		}
	};


	/*
	Mean squared error
	Input:
		yTrue: see in error_num cooments
		yPredict: see in error_num cooments
	Output:
		result: double; refer to
				https://scikit-learn.org/stable/modules/model_evaluation.html#mean-squared-error
	*/
	class MseMeanError: public CosanMetric
	{
		// TODO: might get an error. class ihenritance grammar errors

		double GetError()
		{
			return (yTrue - yPredict).squaredNorm()/yTrue.rows();
		}
	};
	

	/*
	R2 score, computes the coefficient of determination
	Input:
		yTrue: see in error_num cooments
		yPredict: see in error_num cooments
	Output:
		result: double; refer to
				https://scikit-learn.org/stable/modules/model_evaluation.html#r2-score-the-coefficient-of-determination
	*/
	class R2Score: public CosanMetric
	{
		// TODO: might get an error. class ihenritance grammar errors

		double GetError()
		{
			yTrueMean = Constant(yTrue.rows(), yTrue.cols(). yTrue.mean());

			return 1-(yTrue-yPredict).squaredNorm()/(yTrue-yTrueMean).squaredNorm();
		}
	};
	
}

#endif