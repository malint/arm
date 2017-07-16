/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#include "common.h"

#include <iostream>
#include <iterator>
#include <algorithm>

#include "a2io.h"
#include "FeatureConfig.h"
#include "MessageDigest.h"
#include "help_tags.h"
#include "prefs.h"
#include "fmt.h"
#include "OptionParser.h"
#include "OptionHandler.h"
#include "util.h"

namespace aria2 {

void showVersion()
{
  
}

void showUsage(const std::string& keyword,
               const std::shared_ptr<OptionParser>& oparser, const Console& out)
{
  if (keyword.empty()) {
    // Very short version of usage.
    
    return;
  }
  else if (keyword[0] == '#') {
    std::vector<const OptionHandler*> handlers =
        keyword == STR_TAG_ALL ? oparser->findAll()
                               : oparser->findByTag(idHelpTag(keyword.c_str()));
    if (keyword == STR_TAG_ALL) {
      
    }
    else {
      
    }
    
    for (std::vector<const OptionHandler *>::const_iterator
             i = handlers.begin(),
             eoi = handlers.end();
         i != eoi; ++i) {
      write(out, *(*i));
      out->printf("\n");
    }
  }
  else {
    std::vector<const OptionHandler*> handlers =
        oparser->findByNameSubstring(keyword);
    if (!handlers.empty()) {      
      for (std::vector<const OptionHandler *>::const_iterator
               i = handlers.begin(),
               eoi = handlers.end();
           i != eoi; ++i) {
        write(out, *(*i));
        out->printf("\n");
      }
    }
    else {
      write(out, *oparser->find(PREF_HELP));
    }
  }
  if (keyword == strHelpTag(TAG_BASIC)) {
    
  }

}

} // namespace aria2
