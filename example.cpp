/*
  Copyright (C) 2022 hidenorly

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <iostream>
#include <string>
#include "OptParse.hpp"

int main(int argc, char **argv)
{
  std::vector<OptParse::OptParseItem> options;

  options.push_back( OptParse::OptParseItem("-r", "--samplingRate", true, "48000", "Set Sampling Rate"));
  options.push_back( OptParse::OptParseItem("-e", "--encoding", true, "PCM16", "Set Encoding PCM8, PCM16, PCM24, PCM32, PCMFLOAT"));
  options.push_back( OptParse::OptParseItem("-c", "--channel", true, "2", "Set channel 2, 2.1, 4, 4.1, 5, 5.1, 5.1.2, 7.1"));

  OptParse optParser( argc, argv, options );

  std::cout << "options:" << std::endl;
  for( auto& [anOption, anOptionValue] : optParser.values ){
    std::cout << anOption << "=" << anOptionValue << std::endl;
  }

  std::cout << std::endl << "arguments:" << std::endl;
  for( auto& anArg : optParser.args ){
    std::cout << anArg << std::endl;
  }

  return 0;
}