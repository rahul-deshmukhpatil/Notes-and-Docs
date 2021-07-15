#include<memory>

#include "common.hpp"


int main()
{
	// auto dptr = new Derv12;
	
	// error uniq ptr cant handle correct delete in this case
	// auto u_dptr = std::unique_ptr<Base2>(dptr);

	//auto shared_dptr = std::shared_ptr<Base2>(dptr);

	auto u_dptr = std::make_unique<Derv>();
	// error: conversion from ‘unique_ptr<Derv,default_delete<Derv>>’ to non-scalar type ‘unique_ptr<Base,default_delete<Base>>’ requested 
	// std::unique_ptr<Base> b2ptr = u_dptr; 
	std::unique_ptr<Base> b2ptr = std::unique_ptr<Derv>(); 
}
