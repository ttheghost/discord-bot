#include <cstdlib>
#include <iostream>

#include <dpp/dpp.h>

int main() {
  const char *token = std::getenv("BOT_TOKEN");
  if (!token) {
    std::cerr << "Set BOT_TOKEN first\n";
    return 1;
  }

  dpp::cluster bot(token);
  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([](const dpp::slashcommand_t &event) {
    if (event.command.get_command_name() == "ping") {
      event.reply("Pong!");
    }
  });

  bot.on_ready([&bot](const dpp::ready_t &) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_command_create(
          dpp::slashcommand("ping", "Ping pong!", bot.me.id));
    }
  });

  bot.start(dpp::st_wait);
}
