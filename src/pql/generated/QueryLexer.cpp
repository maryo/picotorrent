
// Generated from ./Query.g4 by ANTLR 4.13.2


#include "QueryLexer.h"


using namespace antlr4;

using namespace pt::PQL;


using namespace antlr4;

namespace {

struct QueryLexerStaticData final {
  QueryLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  QueryLexerStaticData(const QueryLexerStaticData&) = delete;
  QueryLexerStaticData(QueryLexerStaticData&&) = delete;
  QueryLexerStaticData& operator=(const QueryLexerStaticData&) = delete;
  QueryLexerStaticData& operator=(QueryLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag querylexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<QueryLexerStaticData> querylexerLexerStaticData = nullptr;

void querylexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (querylexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(querylexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<QueryLexerStaticData>(
    std::vector<std::string>{
      "AND", "OR", "EQ", "CONTAINS", "GT", "GTE", "LT", "LTE", "WS", "INT", 
      "FLOAT", "STRING", "UNIT_SIZE", "UNIT_SPEED", "ID"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'and'", "'or'", "'='", "'~'", "'>'", "'>='", "'<'", "'<='"
    },
    std::vector<std::string>{
      "", "AND", "OR", "EQ", "CONTAINS", "GT", "GTE", "LT", "LTE", "WS", 
      "INT", "FLOAT", "STRING", "UNIT_SIZE", "UNIT_SPEED", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,15,117,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,5,
  	1,6,1,6,1,7,1,7,1,7,1,8,4,8,54,8,8,11,8,12,8,55,1,8,1,8,1,9,3,9,61,8,
  	9,1,9,4,9,64,8,9,11,9,12,9,65,1,10,3,10,69,8,10,1,10,4,10,72,8,10,11,
  	10,12,10,73,1,10,1,10,4,10,78,8,10,11,10,12,10,79,1,11,1,11,5,11,84,8,
  	11,10,11,12,11,87,9,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,3,12,97,
  	8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,
  	111,8,13,1,14,4,14,114,8,14,11,14,12,14,115,1,85,0,15,1,1,3,2,5,3,7,4,
  	9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,1,0,3,3,0,
  	9,10,13,13,32,32,1,0,48,57,2,0,65,90,97,122,128,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,1,31,1,0,0,0,3,35,1,0,0,0,5,38,1,0,0,0,
  	7,40,1,0,0,0,9,42,1,0,0,0,11,44,1,0,0,0,13,47,1,0,0,0,15,49,1,0,0,0,17,
  	53,1,0,0,0,19,60,1,0,0,0,21,68,1,0,0,0,23,81,1,0,0,0,25,96,1,0,0,0,27,
  	110,1,0,0,0,29,113,1,0,0,0,31,32,5,97,0,0,32,33,5,110,0,0,33,34,5,100,
  	0,0,34,2,1,0,0,0,35,36,5,111,0,0,36,37,5,114,0,0,37,4,1,0,0,0,38,39,5,
  	61,0,0,39,6,1,0,0,0,40,41,5,126,0,0,41,8,1,0,0,0,42,43,5,62,0,0,43,10,
  	1,0,0,0,44,45,5,62,0,0,45,46,5,61,0,0,46,12,1,0,0,0,47,48,5,60,0,0,48,
  	14,1,0,0,0,49,50,5,60,0,0,50,51,5,61,0,0,51,16,1,0,0,0,52,54,7,0,0,0,
  	53,52,1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,57,1,0,0,0,
  	57,58,6,8,0,0,58,18,1,0,0,0,59,61,5,45,0,0,60,59,1,0,0,0,60,61,1,0,0,
  	0,61,63,1,0,0,0,62,64,7,1,0,0,63,62,1,0,0,0,64,65,1,0,0,0,65,63,1,0,0,
  	0,65,66,1,0,0,0,66,20,1,0,0,0,67,69,5,45,0,0,68,67,1,0,0,0,68,69,1,0,
  	0,0,69,71,1,0,0,0,70,72,7,1,0,0,71,70,1,0,0,0,72,73,1,0,0,0,73,71,1,0,
  	0,0,73,74,1,0,0,0,74,75,1,0,0,0,75,77,5,46,0,0,76,78,7,1,0,0,77,76,1,
  	0,0,0,78,79,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,22,1,0,0,0,81,85,5,
  	34,0,0,82,84,9,0,0,0,83,82,1,0,0,0,84,87,1,0,0,0,85,86,1,0,0,0,85,83,
  	1,0,0,0,86,88,1,0,0,0,87,85,1,0,0,0,88,89,5,34,0,0,89,24,1,0,0,0,90,91,
  	5,107,0,0,91,97,5,98,0,0,92,93,5,109,0,0,93,97,5,98,0,0,94,95,5,103,0,
  	0,95,97,5,98,0,0,96,90,1,0,0,0,96,92,1,0,0,0,96,94,1,0,0,0,97,26,1,0,
  	0,0,98,99,5,107,0,0,99,100,5,98,0,0,100,101,5,112,0,0,101,111,5,115,0,
  	0,102,103,5,109,0,0,103,104,5,98,0,0,104,105,5,112,0,0,105,111,5,115,
  	0,0,106,107,5,103,0,0,107,108,5,98,0,0,108,109,5,112,0,0,109,111,5,115,
  	0,0,110,98,1,0,0,0,110,102,1,0,0,0,110,106,1,0,0,0,111,28,1,0,0,0,112,
  	114,7,2,0,0,113,112,1,0,0,0,114,115,1,0,0,0,115,113,1,0,0,0,115,116,1,
  	0,0,0,116,30,1,0,0,0,11,0,55,60,65,68,73,79,85,96,110,115,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  querylexerLexerStaticData = std::move(staticData);
}

}

QueryLexer::QueryLexer(CharStream *input) : Lexer(input) {
  QueryLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *querylexerLexerStaticData->atn, querylexerLexerStaticData->decisionToDFA, querylexerLexerStaticData->sharedContextCache);
}

QueryLexer::~QueryLexer() {
  delete _interpreter;
}

std::string QueryLexer::getGrammarFileName() const {
  return "Query.g4";
}

const std::vector<std::string>& QueryLexer::getRuleNames() const {
  return querylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& QueryLexer::getChannelNames() const {
  return querylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& QueryLexer::getModeNames() const {
  return querylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& QueryLexer::getVocabulary() const {
  return querylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView QueryLexer::getSerializedATN() const {
  return querylexerLexerStaticData->serializedATN;
}

const atn::ATN& QueryLexer::getATN() const {
  return *querylexerLexerStaticData->atn;
}




void QueryLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  querylexerLexerInitialize();
#else
  ::antlr4::internal::call_once(querylexerLexerOnceFlag, querylexerLexerInitialize);
#endif
}
