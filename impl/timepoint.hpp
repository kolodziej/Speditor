
namespace speditor {

template <typename Integer,
	typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
Timepoint Timepoint::operator+(Integer add) const
{
	return Timepoint(time_ + add);
}

template <typename Integer,
	typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
Timepoint Timepoint::operator-(Integer subtract) const
{
	return Timepoint(time_ - subtract);
}

template <typename Integer,
	typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
Timepoint& Timepoint::operator+=(Integer add)
{
	time_ += add;
	return *this;
}

template <typename Integer,
	typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
Timepoint& Timepoint::operator-=(Integer subtract)
{
	time_ -= subtract;
	return *this;
}

/*template <typename Integer,
	typename std::enable_if<std::is_integral<Integer>::value, Integer>::type,
	typename std::enable_if<std::is_unsigned<Integer>::value, Integer>::type>
Timepoint::operator Integer() const
{
	return time_;
}*/

}
