#include "ULogger.h"

ULogger * ULogger::m_logger = nullptr;
std::mutex ULogger::m_mutex;

ULogger::ULogger()
{

}

ULogger* ULogger::instance()
{
  std::lock_guard<std::mutex> lock(m_mutex);
  if (!m_logger) {
    m_logger = new ULogger;
  }
  return m_logger;
}

void ULogger::reset()
{
  std::lock_guard<std::mutex> lock(m_mutex);
  if (m_logger) {
    delete m_logger;
    m_logger = nullptr;
  }
}

int ULogger::last(TLoggerData & data)
{
  if (m_datas.size() > 0) {
    data = m_datas.front();
    m_datas.pop();
    return static_cast<int>(m_datas.size());
  }
  return -1; // Нет данных
}

void ULogger::info(const std::string& text)
{
  if (m_logLevel == LLInfo) { // Только если уровень самый низкий
    TLoggerData data;
    data.m_level = LLInfo;
    data.m_text = text;
    m_datas.push(data);
  }
}

void ULogger::warning(const std::string& text)
{
  if (m_logLevel == LLInfo || m_logLevel == LLWarning) { // Только если уровень самый низкий
    TLoggerData data;
    data.m_level = LLWarning;
    data.m_text = text;
    m_datas.push(data);
  }
}

void ULogger::error(const std::string& text)
{
  TLoggerData data;
  data.m_level = LLError;
  data.m_text = text;
  m_datas.push(data);
}

void ULogger::hidden(const std::string& text)
{
  TLoggerData data;
  data.m_level = LLHidden;
  data.m_text = text;
  m_datas.push(data);
}
