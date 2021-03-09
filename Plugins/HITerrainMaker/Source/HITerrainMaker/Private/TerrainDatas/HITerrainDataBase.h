#pragma once
#include "CoreMinimal.h"
#include "HITerrainCommons.h"
#include "HITerrainDataBase.generated.h"

DECLARE_DELEGATE(OnDataGeneratedEvent)

UCLASS()
class UHITerrainDataBase: public UObject, public FRunnable
{
	GENERATED_BODY()

public:
	virtual void InitData(){};
	virtual uint32 Run(){return 0;};
	virtual FChunkInformationPtr GetChunkData(const TPair<int32, int32>& Index);

public:
	void SetSeed(int32 InSeed);
	void SetChunkNums(int32 InChunkNums);
	void SetChunkSampleNums(int32 InChunkSampleNums);

public:
	OnDataGeneratedEvent OnDataGenerated;

protected:
	float GetSample(int32 X, int32 Y);
	void SetSample(int32 X, int32 Y, float Value);

protected:
	virtual void GenerateChunkData(int32 X, int32 Y);

protected:
	int32 Seed;
	int32 ChunkNums;
	int32 ChunkSampleNums;
	bool bIsGenerated = false;
	TMap<TPair<int32, int32>, FChunkInformationPtr> ChunkData;
};