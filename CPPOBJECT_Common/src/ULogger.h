#pragma once

#include <mutex>
#include <queue>

#include "UConstants.h"

/** @class ULogger 
  * @brief Синглтон для вывода отладочной информации */
class ULogger
{
  static ULogger* m_logger; ///< @brief синглтон объект
  static std::mutex m_mutex; ///< @brief Для возможности работы в нескольких потоках

  ELogLevel m_logLevel = LLInfo; ///< @brief Заданный уровень оповещения
  std::queue<TLoggerData> m_datas;  ///< @brief данные до отправки
  /** @brief Конструктор закрытый, что нельзя было создать */
  explicit ULogger();
public:
  /** @brief Запретим конструктор копирования */
  ULogger(ULogger& other) = delete;
  /** @brief Запретим доступ через присвоение */
  void operator=(const ULogger&) = delete;
  /** @brief Возвращает указатель на объект */
  static ULogger* instance();
  /** @brief Удаление при необходимости */
  static void reset();

  //----- Рабочие методы -----
  /** @brief Задает уровень вывода предупреждений */
  void setLevel(ELogLevel level) { m_logLevel = level; }
  /** @brief Записывает последнее сообщение
    * @return Количество оставшихся данных */
  int last(TLoggerData & data);
  /** @brief Вывод информации */
  void info(const std::string & text);
  /** @brief Вывод предупреждения */
  void warning(const std::string& text);
  /** @brief Вывод ошибки */
  void error(const std::string& text);
  /** @brief Вывод скрытого сообщения */
  void hidden(const std::string& text);

};

