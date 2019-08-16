#pragma once

class _declspec(dllexport) CircularBuffer
{
	float *buffer;
	int bufferSize;
	bool overBuffer;
	int addingPosition;
	int desiredLoopSize;

	void IncrementAddingPosition();

public:
	CircularBuffer(int bufferSize = 64000);
	~CircularBuffer();
	void AddValue(float value);
	int GetNumberOfAvaiableValues();
	void ResetBuffer();
	double operator[](int index);
};