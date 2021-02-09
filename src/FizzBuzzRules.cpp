#include "FizzBuzzRules.hpp"
#include <stdexcept>


void	FizzBuzzRules::addRule( Condition con, Action act )
{
	if ( !con || !act )
		throw std::invalid_argument{ "void FizzBuzzRules::addRule(Condition, Action) - neither arguments may be null." };

	m_ruleset.push_back( { con, act } );
}

void	FizzBuzzRules::setDefaultAction( Action act )
{
	m_defaultAction = act;

}

void	FizzBuzzRules::clearDefaultAction()
{
	setDefaultAction( nullptr );
}

void	FizzBuzzRules::applyRules( const Value& i )
{
	bool atLeastOneRuleApplied = false;
	for ( const auto& rule : m_ruleset )
	{
		if ( rule.first( i ) )
		{
			atLeastOneRuleApplied = true;
			rule.second( i );
		}
	}

	if ( !atLeastOneRuleApplied && m_defaultAction )
	{
		m_defaultAction( i );
	}
}






