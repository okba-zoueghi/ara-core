#ifndef ARA_CORE_RESULT_H
#define ARA_CORE_RESULT_H

#include <variant>

template <typename T, typename E>
class Result
{

  std::variant<T,E> mData;

public:

  Result(const T& value): mData(value)
  {

  };

  Result(T&& value): mData(std::move(value))
  {

  };

  Result(const E& error): mData(error)
  {

  };

  Result(E&& error): mData(std::move(error))
  {

  };

  bool HasValue()
  {
    return (mData.index() == 0);
  };

  const T& Value() const &
  {
    return std::get<T>(mData);
  };

  T&& Value() &&
  {
    return std::get<T>(std::move(mData));
  };

};

template<typename E>
class Result<void, E>
{
  std::variant<std::monostate,E> mData;

public:

  Result(): mData()
  {

  };

  Result(const E& error): mData(error)
  {

  };

  Result(E&& error): mData(std::move(error))
  {

  };

  bool HasValue()
  {
    return (mData.index() == 0);
  };

  void Value()
  {

  };
};

#endif
