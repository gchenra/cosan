#ifndef __COSANBO_H_INCLUDED__
#define __COSANBO_H_INCLUDED__
#include <string>
//typedef Eigen::Matrix<float, 1, Eigen::Dynamic, Eigen::RowMajor> EigenVector;
#include <gsl/gsl>

namespace Cosan
{
    class CosanBO
    {
    public:
        CosanBO(){}
//        virtual ~CosanBO();
//        virtual CosanBO *Shallow_copy() const;
//        virtual CosanBO *Deep_copy() const;
        virtual const std::string  GetName() const {
            /**
             * Get the name of the object. It should return "Abstract Object"
             */
            return "Abstract Object";}
//        virtual bool SaveFile(const std::string &path ,const std::string & prefix = "");
//        virtual bool LoadFile(const std::string &path);
//        void PrintModel();
//        virtual bool Equals(CosanBO* other, float accuracy = 0.0);
//        virtual CosanBO* Clone();

    protected:
    };

}

#endif
