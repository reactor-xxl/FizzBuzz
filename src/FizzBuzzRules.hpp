#pragma once
#include <vector>
#include <functional>
#include <tuple>

using Value = int;

class FizzBuzzRules
{
public:
	using Condition	= std::function<bool( Value )>;
	using Action	= std::function<void( Value )>;
	using Rulset	= std::vector<std::pair<Condition, Action>>;
	void addRule(Condition, Action);
//	void removeRule();

	void setDefaultAction( Action );
	void clearDefaultAction();

	void applyRules(const Value&);

private:

	Action		m_defaultAction{ nullptr };
	Rulset		m_ruleset;
};

