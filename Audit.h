//
// Created by Hanz on 06/15/26.
//

#ifndef INVENTORY_AUDIT_H
#define INVENTORY_AUDIT_H

#include <string>

/**
 * @brief View the audit logs
 */
void view_audit_logs();

/**
 * @brief Append the audit message to file
 */
void save_audit_logs(std::string message);

#endif //INVENTORY_AUDIT_H
