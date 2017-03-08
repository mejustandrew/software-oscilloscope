#include "DoubleBufferHandler.h"

DoubleBufferHandler::DoubleBufferHandler()
{
	responseBuffer1 = new ResponseBuffer;
	responseBuffer2 = new ResponseBuffer;
	isBuffer1Inserting = true;
}

DoubleBufferHandler::DoubleBufferHandler(int bufferSize)
{
	responseBuffer1 = new ResponseBuffer(bufferSize);
	responseBuffer2 = new ResponseBuffer(bufferSize);
	isBuffer1Inserting = true;
}

DoubleBufferHandler::~DoubleBufferHandler()
{
	delete responseBuffer1;
	delete responseBuffer2;
}

void DoubleBufferHandler::AddValue(float value)
{
	if (isBuffer1Inserting) responseBuffer1->AddValue(value);
	else responseBuffer2->AddValue(value);
}

IDataResponse * DoubleBufferHandler::GetBufferWithSizeOf(int size)
{
	IDataResponse * response = GetInsertingBuffer()->GetBufferWithLoopSize(size);
	if (response) SwapBuffers();
	return response;
}

IDataResponse * DoubleBufferHandler::GetBufferWithSizeOf(int size, float treshold)
{
	IDataResponse * response = GetInsertingBuffer()->GetBufferWithLoopSize(size, treshold);
	if (response) SwapBuffers();
	return response;
}

ResponseBuffer * DoubleBufferHandler::GetInsertingBuffer()
{
	return isBuffer1Inserting ? responseBuffer1 : responseBuffer2;
}

void DoubleBufferHandler::SwapBuffers()
{
	isBuffer1Inserting = !isBuffer1Inserting;
	if (isBuffer1Inserting)responseBuffer1->Destroy();
	else responseBuffer2->Destroy();
}
