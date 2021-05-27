#include "Archive.h"

namespace Archive
{

const std::filesystem::path cwd = std::filesystem::current_path();

void link(MoonPhase::Moon_Phase phase)
{
  std::string archive_file = std::to_string(phase) + ".luna";
  std::filesystem::create_hard_link(cwd / "dynamic_moon_phases/archive" / archive_file, cwd / "../../../archive/pc/mod/dynamic_moon_phases.archive");
}

void remove()
{
  std::filesystem::remove(cwd / "../../../archive/pc/mod/dynamic_moon_phases.archive");
}

}