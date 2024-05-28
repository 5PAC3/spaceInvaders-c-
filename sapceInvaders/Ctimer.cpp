#include "Ctimer.h"

void Ctimer::Start()
{
    m_StartTime = std::chrono::high_resolution_clock::now();
}

float Ctimer::GetDuration()
{
    std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - m_StartTime;
    return duration.count();
}