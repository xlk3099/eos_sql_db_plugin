#pragma once

#include <eosio/sql_db_plugin/table.hpp>


#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <eosio/chain/block_state.hpp>
#include <eosio/chain/eosio_contract.hpp>
#include <eosio/chain/abi_def.hpp>
#include <eosio/chain/asset.hpp>
#include <eosio/chain/abi_serializer.hpp>

namespace eosio {

using std::string;

struct system_contract_arg{
    system_contract_arg() = default;
    system_contract_arg(const chain::account_name& to, const chain::account_name& from, const chain::account_name& receiver, const chain::account_name& payer, const chain::account_name& name)
    :to(to), from(from), receiver(receiver), payer(payer), name(name)
    {}
    chain::account_name to;
    chain::account_name from;
    chain::account_name receiver;
    chain::account_name payer;
    chain::account_name name;
    chain::account_name account;
};

class actions_table : public mysql_table {
    public:
        actions_table(){}
        actions_table(std::shared_ptr<soci::session> session);
        actions_table(std::shared_ptr<soci_session_pool> session_pool);

        void add( chain::action, std::string, int64_t, std::vector<std::string>); 
        string add_data( chain::action );
        void parse_actions( chain::action );

        static const chain::account_name newaccount;
        static const chain::account_name setabi;

    private:
        // std::shared_ptr<soci::session> m_session;
        std::shared_ptr<soci_session_pool> m_session_pool;
};


} // namespace
FC_REFLECT( eosio::system_contract_arg                        , (to)(from)(receiver)(payer)(name)(account) )



