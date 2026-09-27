
// Generated from ./Query.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace pt::PQL {


class  QueryLexer : public antlr4::Lexer {
public:
  enum {
    AND = 1, OR = 2, EQ = 3, CONTAINS = 4, GT = 5, GTE = 6, LT = 7, LTE = 8, 
    WS = 9, INT = 10, FLOAT = 11, STRING = 12, UNIT_SIZE = 13, UNIT_SPEED = 14, 
    ID = 15
  };

  explicit QueryLexer(antlr4::CharStream *input);

  ~QueryLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace pt::PQL
