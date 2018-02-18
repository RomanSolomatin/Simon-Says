// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnUIScreen.h"
#include "Blueprint/UserWidget.h"


// Sets default values
ASpawnUIScreen::ASpawnUIScreen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnUIScreen::BeginPlay()
{
	Super::BeginPlay();
	
	// Setting widgets.
	if (WidgetObjToSpawn)
	{
		pToSpawnWidget = CreateWidget<UUserWidget>(GetGameInstance(), WidgetObjToSpawn);

		if (pToSpawnWidget.IsValid())
		{
			pToSpawnWidget->AddToViewport();
		}
	}
}

// Called every frame
void ASpawnUIScreen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TWeakObjectPtr<class UUserWidget> ASpawnUIScreen::GetWidget() const
{
	return pToSpawnWidget;
}
