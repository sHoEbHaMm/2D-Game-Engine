#pragma once

#include "Point2D.h"

struct tCounter {

	UINT32 smartrefnum = 0;
	UINT32 weakrefnum = 0;
};

template <class Type>
class WeakPtr;

template <class Type>
class SmartPtr {

public:
	SmartPtr() noexcept;
	SmartPtr(Type* pData) noexcept;
	SmartPtr(const SmartPtr<Type>& pSmartPtr) noexcept;
	SmartPtr(SmartPtr<Type>&& pSmartPtr) noexcept;
	SmartPtr(const WeakPtr<Type>& pWeakPtr) noexcept;

	~SmartPtr() noexcept;

	Type* operator->	() noexcept;

	template <class ParamType>
	SmartPtr<Type>& operator=	(const SmartPtr<ParamType>& pSmartPtr) noexcept;

	template <class ParamType>
	SmartPtr<Type>& operator=	(SmartPtr<ParamType>&& pSmartPtr) noexcept;

	bool			operator==	(const SmartPtr<Type>& pParam) const noexcept;

	Type* GetData() noexcept;

private:

	Type* data;
	tCounter* countref;
};

template <class Type>
SmartPtr<Type>::SmartPtr() noexcept {

	data = nullptr;
	countref = nullptr;
}

template <class Type>
SmartPtr<Type>::SmartPtr(Type* pData) noexcept {

	data = pData;
	countref = new tCounter();

	countref->smartrefnum = 1;
}

template <class Type>
SmartPtr<Type>::SmartPtr(const SmartPtr<Type>& pSmartPtr) noexcept {

	data = pSmartPtr.data;
	countref = pSmartPtr.countref;

	++countref->smartrefnum;
}

template <class Type>
SmartPtr<Type>::SmartPtr(SmartPtr<Type>&& pSmartPtr) noexcept {

	data = pSmartPtr.data;
	countref = pSmartPtr.countref;

	pSmartPtr.data = nullptr;
	pSmartPtr.countref = nullptr;
}


template <class Type>
SmartPtr<Type>::SmartPtr(const WeakPtr<Type>& pWeakPtr) noexcept {

	if (!pWeakPtr.countref->smartrefnum) {

		data = nullptr;
		countref = nullptr;

		return;
	}

	data = pWeakPtr.data;
	countref = pWeakPtr.countref;

	++countref->smartrefnum;
}

template<class Type>
SmartPtr<Type>::~SmartPtr() noexcept
{
	if (countref) {

		--countref->smartrefnum;

		if (!countref->smartrefnum) {

			delete data;

			if (!countref->weakrefnum)
				delete countref;
		}
	}
}

template<class Type>
Type*
SmartPtr<Type>::operator->() noexcept
{
	return data;
}

template <class Type>
template <class ParamType>
SmartPtr<Type>&
SmartPtr<Type>::operator=(const SmartPtr<ParamType>& pSmartPtr) noexcept
{
	if (countref) {

		--countref->smartrefnum;

		if (!countref->smartrefnum) {

			delete data;

			if (!countref->weakrefnum)
				delete countref;
		}
	}

	data = pSmartPtr.data;
	countref = pSmartPtr.countref;

	if (pSmartPtr.countref)
		++countref->smartrefnum;

	return *this;
}

template <class Type>
template <class ParamType>
SmartPtr<Type>&
SmartPtr<Type>::operator= (SmartPtr<ParamType>&& pSmartPtr) noexcept
{
	if (countref) {

		--countref->smartrefnum;

		if (!countref->smartrefnum) {

			delete data;

			if (!countref->weakrefnum)
				delete countref;
		}
	}

	data = pSmartPtr.data;
	countref = pSmartPtr.countref;

	pSmartPtr.data = nullptr;
	pSmartPtr.countref = nullptr;

	return *this;
}

template <class Type>
bool
SmartPtr<Type>::operator==(const SmartPtr<Type>& pParam) const noexcept
{
	if (data == pParam.data)
		return true;
	else
		return false;
}

template <class Type>
Type*
SmartPtr<Type>::GetData() noexcept
{
	return data;
}