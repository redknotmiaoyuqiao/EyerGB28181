#ifndef EYERLIB_EYERSMARTPTR_HPP
#define EYERLIB_EYERSMARTPTR_HPP

#include "EyerSharedCount.hpp"

namespace Eyer
{
    template <typename T>
    class EyerSmartPtr
    {
    public:
        explicit EyerSmartPtr(T * _ptr) {
            ptr = _ptr;
            if(ptr != nullptr){
                sharedCount = new EyerSharedCount();
                sharedCount->Add();
            }
        }

        ~EyerSmartPtr() {
            if(ptr != nullptr && sharedCount->Reduce() <= 0){
                delete ptr;
                delete sharedCount;
            }
        }

        EyerSmartPtr(const EyerSmartPtr & smartPtr) {
            ptr = smartPtr.ptr;
            if(ptr != nullptr){
                smartPtr.sharedCount->Add();
                sharedCount = smartPtr.sharedCount;
            }
        }

        template <typename U>
        EyerSmartPtr(const EyerSmartPtr<U> & smartPtr)
        {
            ptr = static_cast<T *>(smartPtr.ptr);
            if(ptr != nullptr){
                smartPtr.sharedCount->Add();
                sharedCount = smartPtr.sharedCount;
            }
        }

        T & operator * () const {
            return * ptr;
        }

        T * operator -> () const {
            return ptr;
        }

        operator bool() const {
            return ptr;
        }

        long GetCount(){
            return sharedCount->Get();
        }

        const EyerSmartPtr & operator = (const EyerSmartPtr &) = delete;

    public:
        T * ptr = nullptr;
        EyerSharedCount * sharedCount = nullptr;
    };
}

#endif //EYERLIB_EYERSMARTPTR_HPP
