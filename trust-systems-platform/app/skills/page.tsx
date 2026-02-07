import { redirect } from "next/navigation";
import { auth } from "@/lib/auth";
import { prisma } from "@/lib/db";
import { SkillTree } from "@/app/components/skill-tree";

export const metadata = {
  title: "Skill Tree | Trust Systems Platform",
};

export default async function SkillTreePage() {
  const session = await auth();
  if (!session?.user?.id) {
    redirect("/login");
  }

  // Load all user skills
  const userSkills = await prisma.userSkill.findMany({
    where: { userId: session.user.id },
  });

  // Convert to Map for easier lookup
  const skillsMap = new Map(userSkills.map((s) => [s.skillId, s]));

  return (
    <main className="min-h-screen bg-slate-950 text-white">
      <div className="max-w-7xl mx-auto">
        <SkillTree userSkills={skillsMap} />
      </div>
    </main>
  );
}
