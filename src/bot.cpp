#include <discord_bot/bot.hpp>

#include <print>

#include <dpp/dpp.h>

Bot::Bot(const std::string &token) : cluster_(token) {
  cluster_.on_log([this](const dpp::log_t &e) { on_log(e); });
  cluster_.on_ready([this](const dpp::ready_t &e) { on_ready(e); });
  cluster_.on_slashcommand(
      [this](const dpp::slashcommand_t &e) { on_slashcommand(e); });
}

void Bot::run() { cluster_.start(dpp::st_wait); }

void Bot::on_log(const dpp::log_t &event) {
  std::println(stderr, "[{}] {}: {}", dpp::utility::current_date_time(),
               dpp::utility::loglevel(event.severity), event.message);
}

void Bot::on_ready(const dpp::ready_t &) {
  if (dpp::run_once<struct register_bot_commands>()) {
    cluster_.global_command_create(
        dpp::slashcommand("ping", "Ping pong!", cluster_.me.id));
  }
}

void Bot::on_slashcommand(const dpp::slashcommand_t &event) {
  if (event.command.get_command_name() == "ping") {
    event.reply("Pong!");
  }
}
