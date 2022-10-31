// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_Project/C_ClickMove.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeC_ClickMove() {}
// Cross Module References
	UE_PROJECT_API UClass* Z_Construct_UClass_AC_ClickMove_NoRegister();
	UE_PROJECT_API UClass* Z_Construct_UClass_AC_ClickMove();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_UE_Project();
// End Cross Module References
	void AC_ClickMove::StaticRegisterNativesAC_ClickMove()
	{
	}
	UClass* Z_Construct_UClass_AC_ClickMove_NoRegister()
	{
		return AC_ClickMove::StaticClass();
	}
	struct Z_Construct_UClass_AC_ClickMove_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AC_ClickMove_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_UE_Project,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AC_ClickMove_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "C_ClickMove.h" },
		{ "ModuleRelativePath", "C_ClickMove.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AC_ClickMove_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AC_ClickMove>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AC_ClickMove_Statics::ClassParams = {
		&AC_ClickMove::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AC_ClickMove_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AC_ClickMove_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AC_ClickMove()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AC_ClickMove_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AC_ClickMove, 3078145741);
	template<> UE_PROJECT_API UClass* StaticClass<AC_ClickMove>()
	{
		return AC_ClickMove::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AC_ClickMove(Z_Construct_UClass_AC_ClickMove, &AC_ClickMove::StaticClass, TEXT("/Script/UE_Project"), TEXT("AC_ClickMove"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AC_ClickMove);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
