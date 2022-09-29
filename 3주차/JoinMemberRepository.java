package com.example.jubging.Repository;

import com.example.jubging.Model.*;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface JoinMemberRepository extends JpaRepository<JoinMember, JoinMemberId> {
    Boolean existsByUserId(Long userId);
}
