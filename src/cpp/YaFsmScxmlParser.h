#pragma once

#include "tinyxml/tinyxml2.h"

#include <string>
#include <map>
#include <vector>

class YaFsmScxmlParser
{
  friend class YaFsmCppTest;
public:
  YaFsmScxmlParser();

  std::string fileName() const;
  void setFileName(const std::string &fileName);

  bool genCode() const;
  void setGenCode(bool genCode);

  std::string codeOutDir() const;
  void setCodeOutDir(const std::string &codeOutDir);

  void init();
  void readFSM();
  void parseDefinitions(const tinyxml2::XMLElement* );
  void parseFSM(const tinyxml2::XMLElement* );

private:

  class Actions
  {
  public:
    std::string name;

  };

  bool hasSubStates( const tinyxml2::XMLElement* );
  void checkSubEvents( const tinyxml2::XMLElement* );
  void writeInterfaceFSMStateHeader();
  void writeFSMStateBaseHeader();
  void writeFSMStates(const tinyxml2::XMLElement*);
  void writeFSMStates(std::ofstream& header, std::ofstream& source, const tinyxml2::XMLElement*, const std::string& parentName);
  void genStateImpl(std::ofstream& header, std::ofstream& source, const tinyxml2::XMLElement*, const std::string& parentName);

  std::string mFileName;
  std::string mCodeOutDir;
  std::map< std::string, std::string >    mDataModel;
  std::map< std::string, const tinyxml2::XMLElement* > mMembers;
  std::map< std::string, const tinyxml2::XMLElement* > mStates;
  std::map< std::string, int > mTriggers;
  std::map< std::string, int > mEvents;
};
