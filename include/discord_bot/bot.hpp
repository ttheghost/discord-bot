#pragma once

#include <string>

#include <dpp/dpp.h>

class Bot {
public:
  explicit Bot(const std::string &token);
  void run();

private:
  void on_log(const dpp::log_t &event);
  void on_ready(const dpp::ready_t &event);
  void on_slashcommand(const dpp::slashcommand_t &event);

  dpp::cluster cluster_;
};
