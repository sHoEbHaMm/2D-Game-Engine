#pragma once
#pragma once

#include "SmartPtr.h"

template <class Type>
class WeakPtr {

public:

	WeakPtr() noexcept;
	WeakPtr(WeakPtr<Type>& pSmartPtr) noexcept;
	WeakPtr(WeakPtr<Type>&& pSmartPtr) noexcept;
	WeakPtr(SmartPtr<Type>& pWeakPtr) noexcept;

	~WeakPtr() noexcept;

	template <class ParamType>
	WeakPtr<Type>& operator=	(const WeakPtr<ParamType>& pSmartPtr) noexcept;

	template <class ParamType>
	WeakPtr<Type>& operator=	(WeakPtr<ParamType>&& pSmartPtr) noexcept;

	bool				operator==	(const WeakPtr<Type>& pParam) const noexcept;

private:

	Type* data;
	tCounter* refcount;
};

template <class Type>
WeakPtr<Type>::WeakPtr() noexcept {

	data = nullptr;
	refcount = nullptr;
}

template <class Type>
WeakPtr<Type>::WeakPtr(WeakPtr<Type>& pSmartPtr) noexcept {

	if (!pSmartPtr.data) {

		data = nullptr;
		refcount = nullptr;

		return;
	}

	data = pSmartPtr.data;
	refcount = pSmartPtr.refcount;

	++refcount->weakrefnum;
}

template <class Type>
WeakPtr<Type>::WeakPtr(WeakPtr<Type>&& pSmartPtr) noexcept {

	data = pSmartPtr.data;
	refcount = pSmartPtr.refcount;

	pSmartPtr.data = nullptr;
	pSmartPtr.refcount = nullptr;
}

template <class Type>
WeakPtr<Type>::WeakPtr(SmartPtr<Type>& pWeakPtr) noexcept {

	if (!pWeakPtr.data) {

		data = nullptr;
		refcount = nullptr;

		return;
	}

	data = pWeakPtr.data;
	refcount = pWeakPtr.refcount;

	++refcount->weakrefnum;
}

template<class Type>
WeakPtr<Type>::~WeakPtr() noexcept
{
	if (refcount) {

		--refcount->weakrefnum;

		if (!refcount->weakrefnum && !!refcount->smartrefnum)
			delete refcount;
	}
}

template <class Type>
template <class ParamType>
WeakPtr<Type>&
WeakPtr<Type>::operator=(const WeakPtr<ParamType>& pWeakPtr) noexcept
{
	if (refcount) {

		--refcount->weakrefnum;

		if (!refcount->weakrefnum && !refcount->smartrefnum)
			delete refcount;
	}

	data = pWeakPtr.data;
	refcount = pWeakPtr.refcount;

	if (refcount)
		++refcount->weakrefnum;

	return *this;
}

template <class Type>
template <class ParamType>
WeakPtr<Type>&
WeakPtr<Type>::operator=(WeakPtr<ParamType>&& pWeakPtr) noexcept
{
	if (refcount) {

		--refcount->weakrefnum;

		if (!refcount->weakrefnum && !refcount->smartrefnum)
			delete refcount;
	}

	data = pWeakPtr.data;
	refcount = pWeakPtr.refcount;

	pWeakPtr.data = nullptr;
	pWeakPtr.refcount = nullptr;

	return *this;
}

template <class Type>
bool
WeakPtr<Type>::operator==(const WeakPtr<Type>& pParam) const noexcept
{
	if (data == pParam.data)
		return true;
	else
		return false;
}