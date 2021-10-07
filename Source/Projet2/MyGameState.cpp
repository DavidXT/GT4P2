// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"

float AMyGameState::GetScore()
{
	return Score;
}

void AMyGameState::AddScore(float S)
{
	Score += S;
}
