<script setup lang="ts">
import { onMounted } from 'vue';
import DData from "@/components/DData.vue"
import { useFetchLightData } from "@/compositions/useFetchLightData";

const { data, isLoading, error, fetchLightData } = useFetchLightData();

onMounted(() => {
  fetchLightData();
});
</script>

<template>
  <header>
    <h1>Sunspot</h1>
  </header>

  <main>
    <p v-if="isLoading">Loading</p>
    <DData v-else-if="data && !error" :data="data" />
    <p v-else>{{ error }}</p>
  </main>
</template>

<style scoped>
header {
  line-height: 1.5;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

@media (min-width: 1024px) {
  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }
}
</style>
